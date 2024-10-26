from . import db
from sqlalchemy.sql import func

class EPaperDevice(db.Model):
    __tablename__ = 'e_paper_devices'

    e_paper_id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    device_identifier = db.Column(db.String(255), unique=True, nullable=False)
    created_at = db.Column(db.DateTime, nullable=False, server_default=func.now())

    # リレーションシップ
    device_sessions = db.relationship('DeviceSession', backref='epaper_device', lazy=True)
