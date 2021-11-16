SELECT
	score, member_id,
	(SELECT COUNT(*) + 1 FROM ranking WHERE score > b.score) AS rank
FROM
	ranking AS b
ORDER BY 
	RANK ASC		
	