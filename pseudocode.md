START

SET url
SET threshold

FUNCTION fetchURL(url)
    send HTTP request
    return response data

FUNCTION extractPrice(data)
    search price using regex
    return price

data = fetchURL(url)

price = extractPrice(data)

PRINT price

IF price <= threshold
    PRINT alert
ELSE
    PRINT price still above threshold

END
