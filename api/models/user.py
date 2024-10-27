from uuid import uuid4
from sqlalchemy.sql import func
from . import db

class User(db.Model):
    __tablename__ = 'users'

    user_id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    session_id = db.Column(db.String(255), unique=True, nullable=False)
    created_at = db.Column(db.DateTime, nullable=False, server_default=func.now())

    # リレーションシップ
    device_sessions = db.relationship('DeviceSession', backref='user', lazy=True)
    favorite_books = db.relationship('FavoriteBook', backref='user', lazy=True)

    @classmethod
    def get_user_id_from_session_id(cls, session_id):
        user = cls.query.filter_by(session_id=session_id).first()
        return user.user_id if user else None

    @classmethod
    def create_new_user(cls):
        new_session_id = str(uuid4())
        new_user = cls(session_id=new_session_id)
        db.session.add(new_user)
        db.session.commit()
        return new_user.user_id, new_session_id
