from flask import jsonify, request
import base64

from models import db, Book

def get_random_book():
    random_book = Book.get_random_book()
    # FIXME
    # random_book.textを画像に変換
    response_body = {
        "bookId": random_book.book_id,
        "text": random_book.text
    }
    return jsonify(response_body), 200
