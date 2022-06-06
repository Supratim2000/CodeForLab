declare
    ran number(20);
    num number;
begin
    num:='&number';
    for i in 1..num loop
        ran:=dbms_random.random;
        insert into random_num values(ran);
    end loop;
end;
/