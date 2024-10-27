from sqlalchemy.sql import func
from uuid import uuid4
from . import db

class DeviceSession(db.Model):
    __tablename__ = 'device_sessions'

    device_session_id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    e_paper_id = db.Column(db.String(36), db.ForeignKey('e_paper_devices.e_paper_id'), nullable=False)
    user_id = db.Column(db.Integer, db.ForeignKey('users.user_id'), nullable=True)
    session_start = db.Column(db.DateTime, nullable=False, server_default=func.now())
    session_end = db.Column(db.DateTime, nullable=True)

    @classmethod
    def create_new_session(cls, e_paper_id, user_id):
        new_session = cls(e_paper_id=e_paper_id, user_id=user_id)
        db.session.add(new_session)
        db.session.commit()
        return new_session.device_session_id
