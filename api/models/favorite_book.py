from . import db
from sqlalchemy.sql import func

class FavoriteBook(db.Model):
    __tablename__ = 'favorite_books'

    favorite_id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    user_id = db.Column(db.Integer, db.ForeignKey('users.user_id'), nullable=False)
    book_id = db.Column(db.Integer, db.ForeignKey('books.book_id'), nullable=False)
    added_at = db.Column(db.DateTime, nullable=False, server_default=func.now())

    @classmethod
    def add_favorite(cls, user_id, book_id):
        new_favorite = cls(user_id=user_id, book_id=book_id)
        db.session.add(new_favorite)
        db.session.commit()
        return new_favorite.favorite_id

    @classmethod
    def get_favorite_books(cls, user_id):
        favorite_books = cls.query.filter_by(user_id=user_id).all()
        return favorite_books
