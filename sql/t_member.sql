
CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

CREATE TABLE IF NOT EXISTS public."member" (
	id int4 NOT NULL GENERATED ALWAYS AS IDENTITY,
	"name" varchar(256) NOT NULL,
	"password" varchar(256) NOT NULL,

    CONSTRAINT member_un UNIQUE ("name")
);

INSERT INTO IF NOT EXISTS public."member"
(name, password) VALUES ('admin', 'admin');