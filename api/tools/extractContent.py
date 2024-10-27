import requests
import time
from bs4 import BeautifulSoup


def extractContentFromUrl(url):
    retries = 3

    for attempt in range(retries):
        try:
            source = requests.get(url)
            source.encoding = source.apparent_encoding
        except requests.exceptions.ConnectionError as e:
            print(f"接続エラー: {e}")
            if attempt < retries - 1:
                print("再試行します...")
                time.sleep(2)
            else:
                print("最大リトライ回数に達しました。接続に失敗しました。")
                return

    soup = BeautifulSoup(source.text, "html.parser")
    content = soup.find("div", id="contentBody")
    return content
