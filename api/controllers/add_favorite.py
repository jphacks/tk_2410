from flask import jsonify, request
from models import db, User, FavoriteBook

def add_favorite():
    data = request.get_json()
    book_id = data.get("bookId")
    session_id = data.get("sessionId")

    if not book_id or not session_id:
        return jsonify({"error": "Book ID and session ID are required"}), 400

    new_favorite = {
        "message": "本がお気に入りに追加されました",
        "bookId": book_id
    }
    user_id = User.get_user_id_from_session_id(session_id)
    FavoriteBook.add_favorite(user_id, book_id)
    return jsonify(new_favorite), 201
