import time
import sqlalchemy.exc
from flask import Flask

from models import db

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql://user:password@db/hoshizora'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

# Initialize the database with the app
db.init_app(app)

def create_all_with_retry(retries=5, delay=2):
    for _ in range(retries):
        try:
            db.create_all()
            print("Database tables created successfully.")
            return
        except sqlalchemy.exc.OperationalError as e:
            print(f"Retrying database connection: {e}")
            time.sleep(delay)
    raise Exception("Failed to connect to the database after multiple retries")

with app.app_context():
    create_all_with_retry()

@app.route('/', methods=['GET'])
def hello():
    return "Hello, World!!!!"
