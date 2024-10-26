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

api:
	docker compose exec -it api bash

web:
	docker compose exec -it web bash

db:
	docker compose exec -it db bash

.PHONY: up down build fix lint api web db
