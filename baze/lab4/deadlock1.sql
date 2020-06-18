alter procedure deadlock1
as
	begin
		begin transaction
		SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
			update Client set nume = 'Florin' where nume = 'Razvan';
			waitfor delay '00:00:05';
			update Film set nume = 'Once2' where nume = 'Once';
		commit transaction
	end

deadlock1;

update Film set nume = 'Once' where nume = 'Once2';
update Client set nume = 'Razvan' where nume = 'Florin';

Select* from Client;
Select * from Film;