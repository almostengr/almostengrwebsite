drop table if exist mkconversion; 

create table mkconversion as 
select
node.nid, node.type, node.title, node.status, node.created, node.changed
, body.body_value, body.body_format
-- , difficulty.field_difficulty_tid
, (select name from bsal_taxonomy_term_data taxterm where taxterm.tid = difficulty.field_difficulty_tid) as taxterms
, image.field_image_alt, image.field_image_title, image.field_image_width, image.field_image_height
, dfile.uri, dfile.filemime
, body_value as final_output
from bsal_node node
left join bsal_field_data_body body on body.entity_id = node.nid
left join bsal_field_data_field_difficulty difficulty on difficulty.entity_id = node.nid
left join bsal_field_data_field_image image on image.entity_id = node.nid
left join bsal_file_managed dfile on dfile.fid = image.field_image_fid
order by taxterms desc
-- order by field_image_height desc
;

