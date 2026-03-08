# Edge Cases

1. Website blocks scraper requests
   Solution: Add browser User-Agent header

2. Price not found in HTML or JSON
   Return error value (-1)

3. Network failure
   HTTP request may fail

4. Website structure changes
   Regex pattern may break

5. Dynamic JavaScript rendering
   Some websites load prices after page loads

6. Currency format differences
   Examples:
   Rs 2500
   Rs 2,500
   2500.00
