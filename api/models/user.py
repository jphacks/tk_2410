from . import db
from sqlalchemy.sql import func

class User(db.Model):
    __tablename__ = 'users'

    user_id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    session_id = db.Column(db.String(255), unique=True, nullable=False)
    created_at = db.Column(db.DateTime, nullable=False, server_default=func.now())

    # リレーションシップ
    device_sessions = db.relationship('DeviceSession', backref='user', lazy=True)
    favorite_books = db.relationship('FavoriteBook', backref='user', lazy=True)
