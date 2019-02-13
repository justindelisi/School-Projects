DELIMITER //
CREATE TRIGGER MaxPapers
	BEFORE INSERT On report
    FOR EACH ROW
BEGIN
	IF new.memberid in 
    ( select pc.memberid from pcmember pc 
	  where 5 = ( select count(*) from report r
				  where r.memberid = pc.memberid))
	THEN 
		SIGNAL SQLSTATE '45000' SET message_text = 'Max 5 papers per reviewer';
	END IF;
END //






