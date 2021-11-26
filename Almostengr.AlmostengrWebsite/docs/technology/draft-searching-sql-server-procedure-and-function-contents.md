
select * 
from sys.sql_modules m
inner join sys.objects o
on o.object_id = m.object_id
where m.definition like 'text looking for'
