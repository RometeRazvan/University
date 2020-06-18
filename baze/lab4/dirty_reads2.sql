alter procedure dirty_reads2
as
	BEGIN
		SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
			Begin Transaction;
				Select * From Client;
			commit Transaction;
	END

dirty_reads2;