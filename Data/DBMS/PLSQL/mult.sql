declare
    n number;
    ct number;
begin
    n:='&num';
    ct:=1;
    while(3*ct<=n) loop
        dbms_output.put_line('3 X ' || ct || ' =' || 3*ct);
        ct:=ct+1;
    end loop;
end;
/