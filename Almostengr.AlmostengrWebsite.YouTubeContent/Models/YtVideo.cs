using System;

namespace Almostengr.AlmostengrWebsite.YouTubeContent.Models
{
    public class YtVideo
    {
        public string Url { get; set; }
        public string Title { get; set; }
        public DateTime Date_Published { get; set; }
        public string VideoId {
            get { return this.Url.Substring(this.Url.IndexOf("?")); }
        }
        public string Keywords { get; set; }
    }
}