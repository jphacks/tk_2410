import requests
import time
from bs4 import BeautifulSoup
from extractContent import extractContentFromUrl


def scraping():
    pageUrl = "https://bungei-zorozoro.com"
    while pageUrl:
        retries = 3
        for attempt in range(retries):
            try:
                source = requests.get(pageUrl)
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
        urlAndTitle = soup.find_all("td", class_="title")
        urlAndName = soup.find_all("td", class_="name")
        for titleLine, nameLine in zip(urlAndTitle, urlAndName):
            titleLink = titleLine.find("a")
            titleUrl = titleLink.get("href")
            title = titleLink.get_text(strip=True)
            nameLink = nameLine.find("a")
            name = nameLink.get_text(strip=True)
            content = extractContentFromUrl(
                pageUrl + titleUrl
            )
            print(pageUrl + titleUrl, title, name)
            print(content)
            time.sleep(1)

        pager = soup.find("ul", class_="pager")
        nextPage = pager.find("a", class_=lambda x: x != "active")
        nextPageUrl = nextPage.get("href")
        if nextPageUrl and nextPageUrl != "/2":
            pageUrl = pageUrl + nextPageUrl
        else:
            pageUrl = None
    return


scraping()
