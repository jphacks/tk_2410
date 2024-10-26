from . import db
from sqlalchemy.sql import func

class FavoriteBook(db.Model):
    __tablename__ = 'favorite_books'

    favorite_id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    user_id = db.Column(db.Integer, db.ForeignKey('users.user_id'), nullable=False)
    book_id = db.Column(db.Integer, db.ForeignKey('books.book_id'), nullable=False)
    added_at = db.Column(db.DateTime, nullable=False, server_default=func.now())

    # リレーションシップはバックレファレンスで定義されています
