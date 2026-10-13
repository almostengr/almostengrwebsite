import os
import json
import frontmatter # You may need: pip install python-frontmatter

def on_post_build(config):
    # Directory where your source markdown files live
    docs_dir = config['docs_dir']
    # Directory where your site is being built
    site_dir = config['site_dir']

    for root, dirs, files in os.walk(docs_dir):
        for file in files:
            if file.endswith('.md'):
                # Get the relative path to maintain structure
                rel_path = os.path.relpath(os.path.join(root, file), docs_dir)
                
                # Load the markdown file
                post = frontmatter.load(os.path.join(root, file))
                
                # Construct the JSON data object
                data = {
                    "metadata": post.metadata,
                    "content": post.content
                }
                
                # Determine output path (e.g., docs/about.md -> site/about.json)
                json_filename = rel_path.replace('.md', '.json')
                output_path = os.path.join(site_dir, json_filename)
                
                # Ensure directory exists and write the file
                os.makedirs(os.path.dirname(output_path), exist_ok=True)
                with open(output_path, 'w', encoding='utf-8') as f:
                    json.dump(data, f, indent=4)