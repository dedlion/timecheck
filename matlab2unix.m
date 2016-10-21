function tu = matlab2unix(cyear, cmonth, cday, chour, cminute, csec, cmsec)
    datetime_str = datetime(cyear,cmonth,cday,chour,cminute,csec,cmsec);
    datetime_sec = datenum(datetime_str);
    tu = round(864e5 * (datetime_sec - datenum('1970', 'yyyy')));
end


% function tu = matlab2unix_ez(tm)
%     tu = round(864e5 * (tm - datenum('1970', 'yyyy')));
% end
