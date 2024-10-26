# Use a specific version of Python as the base image
FROM python:3.9.10

# Set the working directory in the container
WORKDIR /api

# Environment variables to configure Flask
ENV FLASK_APP=app.py
ENV FLASK_ENV=development
ENV FLASK_DEBUG=1

# Copy requirements and install dependencies
COPY requirements.txt ./
RUN pip install --upgrade pip
RUN pip install -r requirements.txt

# Copy the rest of the application code
COPY . .

# Expose the Flask port
EXPOSE 5000

# Command to run the application
CMD ["flask", "run", "--host=0.0.0.0"]
