from flask import jsonify, request
import base64

from models import db, Book

def add_book(book_url, author, title):
    data = request.get_json()

    if not book_url or not author or not title:
        return jsonify({"error": "missing some required fields"}), 400

    random_book = Book.create_new_book(book_url, author, title)
    return jsonify(random_book), 200
