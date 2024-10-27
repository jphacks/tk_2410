from PIL import Image


# Convert image to white/black pixels and encode them to a 0/1 string
# 0 - black pixel
# 1 - white pixel
def encode_image(image_bytes):
    img = Image.open(image_bytes)

    threshold = 128
    img = img.point(lambda x: 255 if x > threshold else 0, '1')

    pixels = list(img.getdata())
    width, height = img.size

    encoded = ""
    for pixel in pixels:
        encoded += "1" if pixel == 0 else "0"

    return encoded, width, height


if __name__ == "__main__":
    with open("qrcode.png", "rb") as f:
        encoded, width, height = encode_image(f)
        print(f"Encoded: {encoded}")
        print(f"Width: {width}")
        print(f"Height: {height}")
