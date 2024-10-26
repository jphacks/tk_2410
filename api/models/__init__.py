from flask_sqlalchemy import SQLAlchemy

db = SQLAlchemy()

from .user import User
from .epaper_device import EPaperDevice
from .device_session import DeviceSession
from .book import Book
from .favorite_book import FavoriteBook