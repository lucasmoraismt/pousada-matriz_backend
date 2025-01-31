-- Connect to your database first
\c defaultdb;

-- Create Rooms Table
CREATE TABLE IF NOT EXISTS rooms (
    id SERIAL PRIMARY KEY,
    number INT NOT NULL UNIQUE,
    price INT NOT NULL CHECK (price > 0),
    floor INT NOT NULL CHECK (floor >= 0),
    isSuite BOOLEAN NOT NULL DEFAULT FALSE,
    airConditioner BOOLEAN NOT NULL DEFAULT FALSE,
    guestCapacity INT NOT NULL CHECK (guestCapacity > 0),
    bunkbed BOOLEAN NOT NULL DEFAULT FALSE,
    createdAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updatedAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    deletedAt TIMESTAMP
);

-- Create Rentals Table
CREATE TABLE IF NOT EXISTS rentals (
    id SERIAL PRIMARY KEY,
    startDate DATE NOT NULL,
    endDate DATE NOT NULL CHECK (endDate > startDate),
    roomId INT NOT NULL REFERENCES rooms(id) ON DELETE CASCADE,
    createdAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updatedAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    deletedAt TIMESTAMP
);

-- Indexes for Faster Queries
CREATE INDEX idx_rooms_number ON rooms(number);
CREATE INDEX idx_rentals_roomId ON rentals(roomId);
CREATE INDEX idx_rentals_dates ON rentals(startDate, endDate);

-- Trigger for Automatic updatedAt
CREATE OR REPLACE FUNCTION update_updatedAt_column()
RETURNS TRIGGER AS $$
BEGIN
    NEW.updatedAt = NOW();
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

-- Apply Trigger to Rooms
CREATE TRIGGER update_rooms_updatedAt
BEFORE UPDATE ON rooms
FOR EACH ROW EXECUTE FUNCTION update_updatedAt_column();

-- Apply Trigger to Rentals
CREATE TRIGGER update_rentals_updatedAt
BEFORE UPDATE ON rentals
FOR EACH ROW EXECUTE FUNCTION update_updatedAt_column();