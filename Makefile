up:
	docker compose up -d

down:
	docker compose down

build:
	docker compose build

fix:
	docker compose exec web pnpm fix

lint:
	docker compose exec web pnpm lint
