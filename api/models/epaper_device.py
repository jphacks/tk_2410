from . import db
from uuid import uuid4
from sqlalchemy.sql import func
from logging import getLogger

logger = getLogger(__name__)
class EPaperDevice(db.Model):
    __tablename__ = 'e_paper_devices'

    e_paper_id = db.Column(db.String(36), primary_key=True, default=lambda: str(uuid4()), unique=True, nullable=False)
    device_identifier = db.Column(db.String(255), unique=True, nullable=False)
    created_at = db.Column(db.DateTime(timezone=True), server_default=func.now(), nullable=False)

    # リレーションシップ
    device_sessions = db.relationship('DeviceSession', backref='e_paper_device', lazy=True)

    @classmethod
    def create_new_device(cls, device_identifier):
        new_device = cls(device_identifier=device_identifier)
        db.session.add(new_device)
        db.session.commit()
        return new_device

    @classmethod
    def get_device_id_from_device_identifier(cls, device_identifier):
        device = cls.query.filter_by(device_identifier=device_identifier).first()
        if not device:
            device = cls.create_new_device(device_identifier)
        return device.e_paper_id
