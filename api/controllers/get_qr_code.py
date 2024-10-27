from flask import jsonify, request
import json
import os
from io import BytesIO

from models import EPaperDevice
from libs import image_encoder
from libs import qrcode_helper
import logging

logger = logging.getLogger(__name__ + ".get_qr_code")


def get_qr_code():
    body_data = request.get_data().decode("utf-8")
    body = json.loads(body_data)
    device_identifier = body.get("deviceIdentifier")
    if not device_identifier:
        return jsonify({"error": "Device Identifier is required"}), 400

    e_paper_id = EPaperDevice.get_device_id_from_device_identifier(
        device_identifier
    )
    front_url = os.getenv("FRONT_URL")
    target_url = f"{front_url}/{e_paper_id}"
    encoded, width, height = None, None, None
    with BytesIO() as qr_code:
        qrcode_helper.string2qrcode(qr_code, target_url)
        encoded, width, height = image_encoder.encode_image(qr_code)

    return jsonify({
        "width": width,
        "height": height,
        "qrcode": encoded,
    }), 200
