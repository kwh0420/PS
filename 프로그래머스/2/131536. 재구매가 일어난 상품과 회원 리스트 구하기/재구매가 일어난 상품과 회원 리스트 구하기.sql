SELECT 
    USER_ID,
    PRODUCT_ID
FROM 
    ONLINE_SALE
GROUP BY 
    USER_ID, PRODUCT_ID
HAVING 
    COUNT(*) >= 2 -- 동일한 (회원, 상품) 조합이 2번 이상 나타난 경우
ORDER BY 
    USER_ID ASC,    -- 회원 ID 기준 오름차순
    PRODUCT_ID DESC; -- 상품 ID 기준 내림차순