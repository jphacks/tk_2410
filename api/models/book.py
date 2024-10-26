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
