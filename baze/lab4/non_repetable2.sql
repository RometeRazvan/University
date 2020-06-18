alter procedure non_repetable2
as
	BEGIN
		SET TRANSACTION ISOLATION LEVEL READ COMMITTED -- repeatable read 
			Begin Transaction;
				Select * From Client;
				waitfor delay '00:00:08';
				Select * From Client;
			Rollback Transaction;
	END

non_repetable2;

