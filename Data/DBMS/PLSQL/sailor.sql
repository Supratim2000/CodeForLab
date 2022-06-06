declare
    r sailor%rowtype;
    s_id number(10);
begin
    s_id:='&sid';
    select * into r from sailor where sid=s_id;
    dbms_output.put_line('SID= ' || r.sid);
    dbms_output.put_line('NAME= ' || r.name);
    dbms_output.put_line('AGE= ' || r.age);
    dbms_output.put_line('RATING= ' || r.rating);
end;
/