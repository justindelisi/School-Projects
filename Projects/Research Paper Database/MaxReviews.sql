DELIMITER $$
CREATE TRIGGER MaxReviews
	BEFORE INSERT ON report
    FOR EACH ROW
BEGIN
	IF new.paperid in
    ( select p.paperid from paper p 
	  where 3 = ( select count(*) from report r 
				  where r.paperid = p.paperid))
	THEN
		SIGNAL SQLSTATE '45000' SET message_text = 'Only 3 reports per paper';
	END IF;
END $$