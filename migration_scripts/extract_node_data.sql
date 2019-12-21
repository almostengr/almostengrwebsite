drop table if exists mkconversion; 
-- returned 0 rows

create table mkconversion as 
select
node.nid, node.type, node.title, node.status, node.created, node.changed
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
-- returned 0 rows; check table to confirm data is present

update mkconversion
set final_output = 
concat('# ', title, '\n\n', 
       ifnull(concat('!(images/',replace(replace(uri, 'public://home/bitsecal/ae_article_images/', ''), 'public://sites/default/blog_images/', ''),')\n\n'), ''),
       ifnull(concat('**Engineer Level: ', taxterms, '** \n\n'), ''),
       body_value, '\n\n',
      '**Posted: ', from_unixtime(created), '** \n\n',
      '**Updated: ', from_unixtime(changed), '** \n\n')
;
-- updated 144 rows

update mkconversion
set final_output =
replace(replace(replace(replace(final_output, '<p>', ''), '</p>', '\n'), '&nbsp;', ''), '<br />', '')
;

update mkconversion
set final_output = replace(replace(replace(replace(final_output, '<code>', '```'), '</code>', '```\n'),'<pre>', '```'), '</pre>', '```\n')
;

update mkconversion
set final_output =
replace(replace(replace(replace(replace(replace(final_output, '<h1>', '#'), '</h1>', ''), '<h2>', '## '), '</h2>', ''), '<h3>', '### '), '</h3>', '')
;

update mkconversion
set final_output =
replace(replace(final_output, '<li>', '* '), '</li>', '')
;
-- 15 rows updated

