from flask import jsonify, request, make_response
from models import db, User, DeviceSession

def anonymous_login():
    data = request.get_json()
    device_id = data.get("deviceId")

    if not device_id:
        return jsonify({"error": "Device ID is required"}), 400

    response = make_response(jsonify({"message": "ログイン成功"}))
    if "sessionId" not in request.cookies:
        new_user_id, new_session_id = User.create_new_user()
        DeviceSession.create_new_session(device_id, new_user_id)
        response.set_cookie("sessionId", new_session_id, httponly=True, samesite="Strict", secure=True)
        return response, 200
    DeviceSession.create_new_session(device_id)
    return response, 200
