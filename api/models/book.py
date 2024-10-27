from . import db
from sqlalchemy.sql import func

class Book(db.Model):
    __tablename__ = 'books'

    book_id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    book_url = db.Column(db.String(255), nullable=False)
    author = db.Column(db.Text(collation="utf8mb4_unicode_ci"), nullable=False)
    text = db.Column(db.Text(collation="utf8mb4_unicode_ci"), nullable=False)
    created_at = db.Column(db.DateTime, nullable=False, server_default=func.now())

    # リレーションシップ
    favorite_books = db.relationship('FavoriteBook', backref='book', lazy=True)

    @classmethod
    def get_random_book(cls):
        random_book = cls.query.order_by(func.rand()).first()
        return random_book

    @classmethod
    def create_new_book(cls, book_url, author, text):
        new_book = cls(book_url=book_url, author=author, text=text)
        db.session.add(new_book)
        db.session.commit()
        return new_book.book_id

    @classmethod
    def get_book_by_id(cls, book_id):
        book = cls.query.get(book_id)
        return book
