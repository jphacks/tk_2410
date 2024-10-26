from . import db
from sqlalchemy.sql import func

class DeviceSession(db.Model):
    __tablename__ = 'device_sessions'

    device_session_id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    e_paper_id = db.Column(db.Integer, db.ForeignKey('e_paper_devices.e_paper_id'), nullable=False)
    user_id = db.Column(db.Integer, db.ForeignKey('users.user_id'), nullable=True)
    session_start = db.Column(db.DateTime, nullable=False, server_default=func.now())
    session_end = db.Column(db.DateTime, nullable=True)

    # リレーションシップはバックレファレンスで定義されています
