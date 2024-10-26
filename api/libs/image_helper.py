from PIL import Image


# Strip EXIF data from image and save it to buffer in bytes
def strip_exif_from_bytes(buffer, image_bytes):
    with Image.open(image_bytes) as image:
        data = list(image.getdata())
        image_without_exif = Image.new(image.mode, image.size)
        image_without_exif.putdata(data)

        image_without_exif.save(buffer, format="PNG", quality=100)
