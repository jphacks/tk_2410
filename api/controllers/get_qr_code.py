from flask import jsonify, request
import json

from models import db, EPaperDevice

def get_qr_code():
    body = json.loads(request.get_data())
    device_identifier = body.get("deviceIdentifier")
    if not device_identifier:
        return jsonify({"error": "Device Identifier is required"}), 400

    # check device identifier is exists
    e_paper_id = EPaperDevice.get_device_id_from_device_identifier(device_identifier)
    # FIXME
    # create QR code

    # 一旦e_paper_idを返す
    return jsonify({"ePaperId": e_paper_id}), 200
