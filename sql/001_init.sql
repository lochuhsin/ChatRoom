
CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

CREATE TABLE IF NOT EXISTS User (
    id                      varchar (256) PRIMARY KEY,
    username                varchar (256) NOT NULL,
    password                varchar (256) NOT NULL,
    CONSTRAINT              UK_APPUSER_USERNAME UNIQUE (username),
    CONSTRAINT              UK_APPUSER_EMAIL UNIQUE (email)
    );

INSERT INTO User
(id, username, password) VALUES (uuid_generate_v4(), 'admin', 'admin');
