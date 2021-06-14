using System;

namespace Almostengr.AlmostengrWebsite.YouTubeContent.Models
{
    public class YtVideo
    {
        public string Url { get; set; }

        private string _title;
        public string Title
        {
            get { return _title; }
            set { _title = value.Replace(":", ""); }
        }

        public DateTime Date_Published { get; set; }
        public string VideoId
        {
            get { return this.Url.Substring(this.Url.IndexOf("?v=")); }
        }
        public string Keywords { get; set; }
    }
}