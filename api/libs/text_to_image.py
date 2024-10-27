from PIL import Image, ImageDraw, ImageFont
from io import BytesIO

#convert string text to image in bytes
def string2image(text):
  table = str.maketrans({' ':'','　':''})
  text = text.translate(table)

  font_name = "api/libs/font_file.ttc"
  font_size = 20
  font = ImageFont.truetype(font_name, font_size)

  w, h = 200, 300
  im = Image.new("1", (w, h), 1)
  d = ImageDraw.Draw(im)

  top_right_margin = 6
  right_edge = w - top_right_margin
  split_number = int((h - (top_right_margin * 2)) / font_size)
  space_number = (w - (font_size * int(len(text) / split_number + 1))) / 2

  for i in range(len(text)):
    if text[i] == '、' or text[i] == '。':
      d.text((right_edge - space_number - (font_size / 2) - font_size * int(i / split_number), font_size * (i % split_number) + top_right_margin + (font_size / 2)), text[i], fill="black", anchor="lb", font=font)
    else:
      d.text((right_edge - space_number - (font_size / 2) - font_size * int(i / split_number), font_size * (i % split_number) + top_right_margin + (font_size / 2)), text[i], fill="black", anchor="mm", font=font)

  im_bytes = BytesIO()
  im.save(im_bytes, format='PNG')
  im_bytes = im_bytes.getvalue()
  return im_bytes
