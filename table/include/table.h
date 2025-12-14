#pragma once

// Base interface for all P5 table implementations. Concrete table classes
// implement their own apply logic while sharing this common type.
class Table {
public:
    virtual ~Table();

    // Execute the table's logic. Implemented by each derived table type.
    virtual void apply() = 0;
};
