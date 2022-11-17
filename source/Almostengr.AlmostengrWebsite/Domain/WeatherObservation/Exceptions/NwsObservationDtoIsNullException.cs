using System.Runtime.Serialization;

namespace Almostengr.AlmostengrWebsite.Domain.WeatherObservation.Exceptions
{
    [Serializable]
    internal class NwsObservationDtoIsNullException : Exception
    {
        public NwsObservationDtoIsNullException()
        {
        }

        public NwsObservationDtoIsNullException(string message) : base(message)
        {
        }
    }
}