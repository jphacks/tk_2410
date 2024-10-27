from io import BytesIO
from pathlib import Path
import qrcode


# Generate QR code PNG from string and save it to buffer in bytes
def string2qrcode(buffer, s, pixel=200):
    num_cells = 37  # number of cells in a version 5 QR code
    pixel_per_cell = pixel // num_cells

    qr = qrcode.QRCode(
        version=5,
        error_correction=qrcode.constants.ERROR_CORRECT_M,
        box_size=pixel_per_cell,
        border=4,
    )
    qr.add_data(s)
    qr.make(fit=True)
    img = qr.make_image(fill_color="black", back_color="white")
    img.save(buffer, "PNG")


if __name__ == "__main__":
    with BytesIO() as buffer:
        string2qrcode(buffer, "https://example.com")
        Path("qrcode.png").write_bytes(buffer.getvalue())
