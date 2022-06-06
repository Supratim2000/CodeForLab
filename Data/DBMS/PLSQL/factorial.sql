declare
    num number;
    ans number;
begin
    num:='&number';
    ans:=1;
    for i in 1..num loop
        ans:=ans*i;
    end loop;
    dbms_output.put_line('Factorial: ' || ans);
end;
/