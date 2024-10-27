from flask import jsonify, request
from models import db, User, FavoriteBook, Book
from logging import getLogger

logger = getLogger(__name__)

def get_favorites():
    user_id = User.get_user_id_from_session_id(request.cookies.get("sessionId"))
    if not user_id:
        return jsonify({"error": "User is not logged in"}), 401
    favorite_books = FavoriteBook.get_favorite_books(user_id)
    response_body_list = []
    for favorite_book in favorite_books:
        book = Book.get_book_by_id(favorite_book.book_id)
        response_body_list.append({
            "bookId": book.book_id,
            "text": book.text
        })
    return jsonify(response_body_list), 200
