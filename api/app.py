from flask import Flask, jsonify, request, make_response
from logging import getLogger
from werkzeug.exceptions import HTTPException

from controllers import anonymous_login, get_favorites, add_favorite, get_random_book, get_qr_code
from models.database import init_db

logger = getLogger(__name__)

app = Flask(__name__)
# FIXME divide to config
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql://user:password@db/hoshizora'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.json.ensure_ascii = False

# Initialize the database with the app
init_db(app)

# FIXME divide to error.py
# Error handling
@app.errorhandler(Exception)
def handle_exception(e):
    logger.error(e)
    if isinstance(e, HTTPException):
        return jsonify(error=str(e)), e.code
    return jsonify(error="Server Error"), 500

# Routes
app.add_url_rule("/anonymous-login", "anonymous_login", anonymous_login, methods=["POST"])
app.add_url_rule("/books/favorites", "get_favorites", get_favorites, methods=["GET"])
app.add_url_rule("/books/favorites", "add_favorite", add_favorite, methods=["POST"])
app.add_url_rule("/books/random", "get_random_book", get_random_book, methods=["GET"])
app.add_url_rule("/books/qrcode", "get_qr_code", get_qr_code, methods=["POST"])

from controllers import add_book
sample_book = {
    "book_url": "https://example.com",
    "author": "example_author",
    "text": "this is a sample book"
}
app.add_url_rule("/books", "add_book", lambda: add_book(sample_book["book_url"], sample_book["author"], sample_book["text"]), methods=["POST"])