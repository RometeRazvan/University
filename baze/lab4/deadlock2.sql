alter procedure deadlock2
as
	begin
		begin transaction
		SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
			update Film set nume = 'Once' where nume = 'Once2';
			waitfor delay '00:00:05';
			update Client set nume = 'Razvan' where nume = 'Florin';
		commit transaction
	end

deadlock2;