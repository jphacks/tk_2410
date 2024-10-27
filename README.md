# ひとひら文庫

## 製品概要

### 背景(製品開発のきっかけ、課題等）
“大人”の読書離れ。
家事や仕事が忙しい、最近の風潮（早期からのキャリア形成、自己啓発など）
着眼点：小説を読むことのリスクは高く、タスクとして重いのではないか
着想点：１行だけ物語を読んでみる。しかも読み直せない。その時だけの一文。
小説とのタッチポイントを増やし、新しい読書体験の一つとして提供したい。
自分が気に入った１行を記録することで、本を読み始めるはハードルを低くしたい
### 製品説明（具体的な製品の説明）
電子ペーパーで小説の冒頭文もしくはキーフレーズや最後の文などを１行表示させる。
### 特長
#### 1. 特長1
気になったら、もしくは気に入ったらお気に入りボタンが押せる
#### 2. 特長2
お気に入りがWebアプリに記録され、そこで何の本なのかわかる
#### 3. 特長3
本を閉じるとリセットされて、新しい文が表示させる

### 解決出来ること
忙しい現代人のための新しい読書の形を提供する
### 今後の展望
いろいろな小説投稿サイトや出版社と連携し、Webアプリで本を購入できるようにする
### 注力したこと（こだわり等）
* ハードのドキュメントに間違いがあるなか尽力した。

## 開発技術
### 活用した技術
#### API・データ
[zorozoro - 文芸寄港](https://bungei-zorozoro.com/)

#### フレームワーク・ライブラリ・モジュール
* React
* Flask
* Node.js
* Vite
* MySQL
* Docker

#### デバイス
* 4.3inch e-Paper UART Module（電子ペーパー）
* esp32-WROOM-32
* ドアセンサースイッチ（リードスイッチ）SPS-320
* ボタン

### 独自技術
#### ハッカソンで開発した独自機能・技術
* 電子ペーパーで文字、QRコードを出力する。
* Webアプリから小説を閲覧できる。
