declare
    rng number;
begin
    rng:='&range';
    for i in 1..rng loop
        if mod(i,2)=0 then dbms_output.put_line(i || ' ');
        end if;
    end loop;
end;
/