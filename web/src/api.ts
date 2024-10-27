import createClient from "openapi-fetch";
import type { paths } from "./schema";

const client = createClient<paths>({
  baseUrl: "http://localhost:5000",
  mode: "cors",
  credentials: "include",
  },
);
// Function to handle /anonymous-login request
export async function anonymousLogin(deviceId: string) {
  const {
    data, // Only present if 2XX response
    error, // Only present if 4XX or 5XX response
  } = await client.POST("/anonymous-login", {
    headers: {
      "Content-Type": "application/json",
    },
    body: {
      deviceId: deviceId,
    },
  });

  if (data) {
    console.log("Login successful:", data);
  } else if (error) {
    console.error("Login error:", error);
  }
}

// Function to retrieve favorite books
export async function getFavoriteBooks() {
  const {
    data, // Only present if 2XX response
    error, // Only present if 4XX or 5XX response
  } = await client.GET("/books/favorites", {
    headers: {
      "Content-Type": "application/json",
    }
  });

  if (data) {
    console.log("Favorite books:", data);
  } else if (error) {
    console.error("Error fetching favorite books:", error);
  }
}